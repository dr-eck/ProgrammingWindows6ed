// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Media;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::HowToAsync1::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    winrt::fire_and_forget MainWindow::OnButtonClick(IInspectable const&, RoutedEventArgs const&)
    {
        //auto rv{ ShowDlg(contentGrid(), myButton()) };
        ContentDialog dialog;
        dialog.Title(box_value(L"title"));
        dialog.Content(box_value(L"content"));
        dialog.PrimaryButtonText(L"Red");
        dialog.SecondaryButtonText(L"Blue");
        dialog.CloseButtonText(L"Close");
        dialog.XamlRoot(myButton().XamlRoot());

        auto cdr = co_await dialog.ShowAsync();

        if (cdr == ContentDialogResult::Primary)
        {
            SolidColorBrush myBrush{ Microsoft::UI::Colors::Red() };
            contentGrid().Background(myBrush);
        }
        else if (cdr == ContentDialogResult::Secondary)
        {
            SolidColorBrush myBrush{ Microsoft::UI::Colors::Blue() };
            contentGrid().Background(myBrush);
        }
    }
}
