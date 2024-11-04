#include "script.h"
#include "keyboard.h"
#include "scriptmenu.h"

// int Initfont()
// {
//     // 字体文件路径（系统的微软雅黑字体）
//     const char *fontPath = "GlossTrainer\\msyh.ttc";

//     // 字体大小（通常为 72.0f）
//     float fontSize = 72.0f;

//     // 注册字体并获取 fontId
//     int fontId = registerFont(fontPath, fontSize);

//     return fontId;
// }

MenuBase *CreatePlayerMenu(MenuController *controller)
{
    MenuBase *menu = new MenuBase(new MenuItemTitle(("玩家选项")));
    controller->RegisterMenu(menu);
    return menu;
}

MenuBase *CreatePlayerTeleportMenu(MenuController *controller)
{
    MenuBase *menu = new MenuBase(new MenuItemListTitle(("传送选项")));
    controller->RegisterMenu(menu);

    return menu;
}

MenuBase *CreateMainMenu(MenuController *controller)
{

    auto menu = new MenuBase(new MenuItemListTitle("RDRNativeTrainer By:小莫"));
    controller->RegisterMenu(menu);

    menu->AddItem(new MenuItemMenu("玩家选项", CreatePlayerMenu(controller)));
    menu->AddItem(new MenuItemMenu("传送选项", CreatePlayerTeleportMenu(controller)));

    return menu;
}

void main()
{

    auto menuController = new MenuController();
    auto mainMenu = CreateMainMenu(menuController);

    while (true)
    {
        if (!menuController->HasActiveMenu() && MenuInput::MenuSwitchPressed())
        {
            MenuInput::MenuInputBeep();
            menuController->PushMenu(mainMenu);
        }
        menuController->Update();
        WAIT(0);
    }
}

void ScriptMain()
{
    // Initfont();
    srand(GetTickCount64());
    main();
}