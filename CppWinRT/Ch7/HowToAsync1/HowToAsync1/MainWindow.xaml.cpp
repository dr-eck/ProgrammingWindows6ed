#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Popups;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Controls::Primitives;
using namespace Microsoft::UI::Xaml::Data;
using namespace Microsoft::UI::Xaml::Input;
using namespace Microsoft::UI::Xaml::Media;
using namespace Microsoft::UI::Xaml::Navigation;

namespace winrt::HowToAsync1::implementation
{
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