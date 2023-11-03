// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PrimitivePad::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    winrt::fire_and_forget MainWindow::OnFileOpenButtonClick(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {
        return winrt::fire_and_forget();
    }

    winrt::fire_and_forget MainWindow::OnFileSaveAsButtonClick(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {
        return winrt::fire_and_forget();
    }

    winrt::fire_and_forget MainWindow::OnWrapButtonChecked(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {
        return winrt::fire_and_forget();
    }
}
