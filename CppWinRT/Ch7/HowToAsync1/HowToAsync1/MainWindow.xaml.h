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

        // docs: https://learn.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/concurrency-2#fire-and-forget
        // Specifically, "winrt::fire_and_forget is also useful as the return type of your event handler 
        // when you need to perform asynchronous operations in it."
        // someone on StackOverflow mentioned that fire_and_forget is like async void in C#
        // Also from StackOverflow (https://stackoverflow.com/questions/65593996/winrtfire-and-forget-what-does-this-do)
        // Apart from documentation for Fire and forget, note the following: the function itself uses co_await operator in its body.
        // This requires that the function itself is coroutine friendly and could be compiled into "stackless" form, 
        // for asynchronous execution. void return type does not work out, but fire_and_forget struct is okay because
        //  C++ / WinRT defines coroutine handling for it, as explained by the documentation.
        // Think of this as void which can be asynchronous and has no need to be waited on.
        winrt::fire_and_forget OnButtonClick(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::HowToAsync1::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
