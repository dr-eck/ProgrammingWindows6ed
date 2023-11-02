﻿#pragma once

#include "MainWindow.g.h"

namespace winrt::GradientBrushMarkup::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::GradientBrushMarkup::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
