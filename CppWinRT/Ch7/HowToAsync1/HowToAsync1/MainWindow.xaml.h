#pragma once

#include "MainWindow.g.h"

namespace winrt::HowToAsync1::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
    public:
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void OnButtonClick(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::HowToAsync1::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
