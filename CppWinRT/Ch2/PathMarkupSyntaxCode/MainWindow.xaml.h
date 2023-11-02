#pragma once

#include "MainWindow.g.h"
#include <string>

namespace winrt::PathMarkupSyntaxCode::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);

    private:
        Microsoft::UI::Xaml::Media::Geometry PathMarkupToGeometry(const std::wstring& pathMarkup);
    };
}

namespace winrt::PathMarkupSyntaxCode::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
