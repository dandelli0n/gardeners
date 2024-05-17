//
// Created by Vikiii on 14/05/2023.
//

#include "Game.hpp"
#include <iostream>
#include <fstream>
#include "Geometry.hpp"

Game::Game(Renderer* renderer) : renderer(renderer)
{
    TomatoTile::registerMakerFunc();
    BeanTile::registerMakerFunc();
    LettuceTile::registerMakerFunc();
    SunflowerTile::registerMakerFunc();

    plants = Plant::loadPlants();
    for (int i = 0; i < plants.size(); ++i)
    {
        if (plants[i].getName() == "Portal")
        {
            portal = plants[i];
        }
    }
    loadedTasks = Task::loadTasks();

    setupGame();

    gameResources.mainFont = TTF_OpenFont("Macondo-Regular.ttf", 32);
    gameResources.bigFont = TTF_OpenFont("Macondo-Regular.ttf", 64);
}

int Game::getCoins() const
{
    return coins;
}

void Game::run()
{
    gameLoop();
}

void Game::gameLoop()
{
    while(shouldRun)
    {
        renderer->clearScreen(gameResources.backgroundColor);

        switch (view)
        {
            case View::MainMenu:
                mainMenuView();
                break;
            case View::MainGame:
                mainGameView();
                break;
            case View::NewGame:
                newGameView();
                break;
            case View::QuestsView:
                questsView();
                break;
            case View::EndGame:
                endGameView();
                break;
        }

        eventHandler();

        renderer->present();
    }
}

void Game::eventHandler()
{
    input.clicked = false;
    input.enter = false;
    input.scrollUp = false;
    input.scrollDown = false;
    input.rotate = false;
    input.mirror = false;
    input.testInput = false;

    input.mouseX = 0;
    input.mouseY = 0;

    SDL_GetMouseState(&input.mouseX, &input.mouseY);

    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
        {
            if(e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                shouldRun = false;

            if (e.key.keysym.scancode == SDL_SCANCODE_RETURN)
                input.enter = true;

            if (e.key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
            {
                int len = strlen(input.textInputBuffer);

                if (len != 0)
                    input.textInputBuffer[len - 1] = '\0';
            }

            if (e.key.keysym.scancode == SDL_SCANCODE_DELETE)
            {
                input.clearTextInput();
            }


            if (e.key.keysym.scancode == SDL_SCANCODE_R)
            {
                input.rotate = true;
            }

            if (e.key.keysym.scancode == SDL_SCANCODE_T)
            {
                input.testInput = true;
            }


            if (e.key.keysym.scancode == SDL_SCANCODE_Q)
            {
                input.mirror = true;
            }

        }

        if (e.type == SDL_MOUSEWHEEL)
        {
            if (e.wheel.y > 0)
            {
                input.scrollUp = true;
            }
            else if (e.wheel.y < 0)
            {
                input.scrollDown = true;
            }
        }

        if (e.type == SDL_TEXTINPUT)
        {
            strcat(input.textInputBuffer, e.text.text);
        }

        if (e.type == SDL_QUIT)
        {
            shouldRun = false;
        }

        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            input.clicked = true;
        }
    }
}

void Game::mainMenuView()
{
    Renderer::TextureWithRect menuTexts[2];

    for (int i = 0; i < 2; ++i)
    {
        menuTexts[i].rect.x = 64;
        menuTexts[i].rect.y = (i * 72) + 64;
    }

    renderer->createLineOfText("New Game", &menuTexts[0], gameResources.mainFont, gameResources.mainTextColor);
    renderer->createLineOfText("Exit", &menuTexts[1], gameResources.mainFont, gameResources.mainTextColor);

    if (input.clicked)
    {
        if (checkCoordsInRect(input.mouseX, input.mouseY, bigger(menuTexts[0].rect, 16)))
        {
            input.clearTextInput();
            setupGame();
            switchView(View::NewGame);
        }


        if (checkCoordsInRect(input.mouseX, input.mouseY, bigger(menuTexts[1].rect, 16)))
            shouldRun = false;
    }

    for (auto & menuText : menuTexts)
    {
        if (checkCoordsInRect(input.mouseX, input.mouseY, bigger(menuText.rect, 16)  ))
            renderer->fillRect(bigger(menuText.rect, 16), gameResources.mainBrightColor);

        renderer->drawRect(bigger(menuText.rect, 16), gameResources.mainTextColor);


        renderer->render(menuText);
    }
}

void Game::mainGameView()
{
    board.draw(renderer);

    int sidebarX = 12 * 64;
    int sidebarW = windowWidth - sidebarX;

    SDL_Rect previewArea = {sidebarX + 32, 32, 4 * 64, 4 * 64};
    SDL_Rect sidebarArea = { sidebarX, 0, sidebarX + 5 * 64 - 1, windowHeight};

    renderer->fillRect(previewArea, gameResources.mainTextColor);

    renderer->drawRect(sidebarArea, gameResources.mainTextColor);

    int tileX = std::min(input.mouseX / 64, 10);
    int tileY = std::min(input.mouseY / 64, 10);

    SDL_Rect rectOnBoard = {0,0,64,64};
    bool canPlace = board.canPlacePlant(tileX, tileY, currentPlant);

    bool canPlaceOnBoard = true;
    //check if plant cn be placed on the board in any formation - rotated, mirrored (that's 8 ways if we are unlucky) TODO -> somehow do it without bruteforce, use that as last resort


    if (input.rotate)
    {
        currentPlant.getShape().rotate();
    }

    if (input.mirror)
    {
        currentPlant.getShape().mirror();
    }

    if (input.scrollUp)
    {
        currentPlant.nextSelection();
        demoTile = currentPlant.getNewTile();
    }

    if (input.scrollDown)
    {
        currentPlant.previousSelection();
        demoTile = currentPlant.getNewTile();
    }

    if(input.testInput)
    {
        canPlaceOnBoard = false;
    }

    if(!canPlaceOnBoard)
    {
        currentPlant = portal;
    }

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (currentPlant.getShape().at(x, y))
            {
                demoTile->draw(renderer, sidebarX + 32 + x * 64, 32 + y * 64);

                rectOnBoard.x = (tileX + x) * 64;
                rectOnBoard.y = (tileY + y) * 64;

                if (canPlace)
                    renderer->fillRect(rectOnBoard, gameResources.hoverOkColor);
                else
                    renderer->fillRect(rectOnBoard, gameResources.hoverBadColor);
            }
        }
    }


    if (input.clicked && input.mouseX < board.getW() * 64)
    {

        if (board.placePlant(tileX, tileY, currentPlant))
        {
            coins = board.getCoins();
            currentTime += currentPlant.getDuration();

            if (currentTime >= getSeasonTime())
            {
                nextSeason();
                if (season == Season::Spring)
                {
                    switchView(View::EndGame);
                }
            }

            currentPlant = plants[rand() % plants.size()];
            demoTile = currentPlant.getNewTile();
        }
    }

    Renderer::TextureWithRect plantNameText;
    renderer->createLineOfText(currentPlant.getName(), &plantNameText, gameResources.mainFont, gameResources.mainTextColor);
    renderer->render(plantNameText, sidebarW / 2 + sidebarX - plantNameText.rect.w / 2, previewArea.y + previewArea.h + 32);

    Renderer::TextureWithRect questsButton;
    renderer->createLineOfText("Quests", &questsButton, gameResources.bigFont, gameResources.mainTextColor);
    questsButton.rect.x = sidebarW / 2 + sidebarX - questsButton.rect.w / 2;
    questsButton.rect.y = windowHeight - 102;

    if (checkCoordsInRect(input.mouseX, input.mouseY, bigger(questsButton.rect, 16)))
    {
        if (input.clicked)
        {
            switchView(View::QuestsView);
        }

        renderer->fillRect(bigger(questsButton.rect, 16), gameResources.mainBrightColor);
    }


    renderer->drawRect(bigger(questsButton.rect, 16), gameResources.mainTextColor);
    renderer->render(questsButton);

    Renderer::TextureWithRect seasonText;
    renderer->createLineOfText(getSeasonString(), &seasonText, gameResources.bigFont, gameResources.mainTextColor);
    renderer->render(seasonText, sidebarW / 2 + sidebarX - seasonText.rect.w / 2, windowHeight - 232);

    Renderer::TextureWithRect durationText;
    renderer->createLineOfText("Time:r" + std::to_string(currentTime) + "/" + std::to_string(getSeasonTime()), &durationText, gameResources.mainFont, gameResources.mainTextColor);
    renderer->render(durationText, sidebarX + 32, windowHeight - 152);

    Renderer::TextureWithRect coinsText;
    renderer->createLineOfText("Coins: " + std::to_string(coins), &coinsText, gameResources.mainFont, gameResources.mainTextColor);
    renderer->render(coinsText, sidebarX + 32, windowHeight - 32);

    Renderer::TextureWithRect pointsText;
    renderer->createLineOfText("Points: " + std::to_string(points), &pointsText, gameResources.mainFont, gameResources.mainTextColor);
    renderer->render(pointsText, sidebarX + 32 + 160, windowHeight - 32);
}

void Game::newGameView()
{
    Renderer::TextureWithRect promptText;
    Renderer::TextureWithRect nameText;
    Renderer::TextureWithRect okText;
    Renderer::TextureWithRect backText;

    bool accepted = false;

    renderer->createLineOfText("Enter your name!", &promptText, gameResources.bigFont, gameResources.mainTextColor);

    renderer->createLineOfText("< Back", &backText, gameResources.mainFont, gameResources.mainTextColor);
    renderer->createLineOfText("Ok >", &okText, gameResources.mainFont, gameResources.mainTextColor);

    std::string nameString = input.textInputBuffer;
    auto textColorToUse = gameResources.mainTextColor;
    if (nameString.empty())
    {
        textColorToUse = gameResources.mainBrightColor;
        nameString = "<Type Here>";
    }

    renderer->createLineOfText(nameString, &nameText, gameResources.bigFont, textColorToUse);

    renderer->render(promptText, (windowWidth / 2) - promptText.rect.w / 2, 70);
    renderer->render(nameText, (windowWidth / 2) - nameText.rect.w / 2, 160);


    // Handle buttons

    okText.rect.x = windowWidth - okText.rect.w - 50;
    okText.rect.y = windowHeight - okText.rect.h - 50;

    if (checkCoordsInRect(input.mouseX, input.mouseY, bigger(okText.rect, 16)))
    {
        renderer->fillRect(bigger(okText.rect, 16), gameResources.mainBrightColor);

        if (input.clicked)
            accepted = true;
    }
    renderer->render(okText);
    renderer->drawRect(bigger(okText.rect, 16), gameResources.mainTextColor);


    backText.rect.x = 50;
    backText.rect.y = windowHeight - backText.rect.h - 50;

    if (checkCoordsInRect(input.mouseX, input.mouseY, bigger(backText.rect, 16)))
    {
        renderer->fillRect(bigger(backText.rect, 16), gameResources.mainBrightColor);

        if (input.clicked)
        {
            switchView(View::MainMenu);
        }

    }

    renderer->drawRect(bigger(backText.rect, 16), gameResources.mainTextColor);
    renderer->render(backText);

    if (input.enter)
        accepted = true;

    if (accepted && nameString != "<Type Here>")
    {
        playername = nameString;
        switchView(View::MainGame);
    }
}

void Game::switchView(Game::View newView)
{
    view = newView;
    input.clearTextInput();
}

void Game::nextSeason()
{
    auto questIds = getCurrentQuestIds();

    points += tasks[questIds.first].evaluate(*this, board);
    points += tasks[questIds.second].evaluate(*this, board);
    points += coins;

    switch (season)
    {
        case Season::Spring:
            season = Season::Summer;
            break;
        case Season::Summer:
            season = Season::Fall;
            break;
        case Season::Fall:
            season = Season::Winter;
            break;
        case Season::Winter:
            season = Season::Spring;
            break;
    }

    currentTime = 0;
}

std::string Game::getSeasonString() const
{
    switch (season)
    {
        case Season::Spring:
            return "Spring";
        case Season::Summer:
            return "Summer";
        case Season::Fall:
            return "Fall";
        case Season::Winter:
            return "Winter";
    }

    return "";
}

int Game::getSeasonTime() const
{
    switch (season)
    {
        case Season::Spring:
        case Season::Summer:
            return 8;

        case Season::Fall:
            return 7;

        case Season::Winter:
            return 6;
    }

    return 0;
}

void Game::questsView()
{
    Renderer::TextureWithRect questsTitleText;
    renderer->createLineOfText("Your quests (Press enter to return to the game)", &questsTitleText, gameResources.bigFont, gameResources.mainTextColor);
    renderer->render(questsTitleText, windowWidth / 2 - questsTitleText.rect.w / 2, 60);

    if (input.enter)
    {
        switchView(View::MainGame);
    }

    for (int i = 0; i < 4; i++)
    {
        Renderer::TextureWithRect taskText;
        renderer->createLineOfText(tasks[i].getName() + ": " + tasks[i].getDesc(), &taskText, gameResources.mainFont, gameResources.mainTextColor);
        taskText.rect.x = 32;
        taskText.rect.y = 122 + i * 44;

        if (i == getCurrentQuestIds().first || i == getCurrentQuestIds().second)
        {
            renderer->fillRect(bigger(taskText.rect, 6), gameResources.mainBrightColor);
        }

        renderer->render(taskText);
    }


    Renderer::TextureWithRect backButton;
    renderer->createLineOfText("< Back", &backButton, gameResources.bigFont, gameResources.mainTextColor);
    backButton.rect.x = 64;
    backButton.rect.y = windowHeight - 102;

    if (checkCoordsInRect(input.mouseX, input.mouseY, bigger(backButton.rect, 16)))
    {
        if (input.clicked)
        {
            switchView(View::MainGame);
        }

        renderer->fillRect(bigger(backButton.rect, 16), gameResources.mainBrightColor);
    }

    renderer->drawRect(bigger(backButton.rect, 16), gameResources.mainTextColor);
    renderer->render(backButton);


}

std::pair<int, int> Game::getCurrentQuestIds()
{
    switch (season)
    {
        case Season::Spring:
            return {0, 1};

        case Season::Summer:
            return {1, 2};

        case Season::Fall:
            return {2, 3};

        case Season::Winter:
            return {3, 0};
    }
    return {0, 0};
}

void Game::endGameView()
{
    std::string pointsString = "You earned " + std::to_string(points) + " points!";
    Renderer::TextureWithRect pointsText;
    renderer->createLineOfText(pointsString, &pointsText, gameResources.bigFont, gameResources.mainTextColor);
    renderer->render(pointsText, windowWidth / 2 - pointsText.rect.w / 2, 160);

    Renderer::TextureWithRect gameOverText;
    renderer->createLineOfText("Game over! <Enter to exit>", &gameOverText, gameResources.bigFont, gameResources.mainTextColor);
    renderer->render(gameOverText, windowWidth / 2 - gameOverText.rect.w / 2, 60);

    if (input.enter)
        shouldRun = false;

    Renderer::TextureWithRect exitButton;
    renderer->createLineOfText("Back to Menu", &exitButton, gameResources.bigFont, gameResources.mainTextColor);
    exitButton.rect.x = windowWidth / 2 - exitButton.rect.w / 2;
    exitButton.rect.y = windowHeight - 102;

    if (checkCoordsInRect(input.mouseX, input.mouseY, bigger(exitButton.rect, 16)))
    {
        if (input.clicked)
        {
            switchView(View::MainMenu);
        }

        renderer->fillRect(bigger(exitButton.rect, 16), gameResources.mainBrightColor);
    }

    renderer->drawRect(bigger(exitButton.rect, 16), gameResources.mainTextColor);
    renderer->render(exitButton);
}

void Game::setupGame()
{
    season = Season::Spring;
    points = 0;
    coins = 0;

    board.clear();

    loadedTasks = Task::loadTasks();
    for (auto & task : tasks)
    {
        int index = rand() % loadedTasks.size();
        task = loadedTasks[index];
        loadedTasks.erase(loadedTasks.begin() + index);
    }

    currentPlant = plants[rand() % plants.size()];
    demoTile = currentPlant.getNewTile();
}

