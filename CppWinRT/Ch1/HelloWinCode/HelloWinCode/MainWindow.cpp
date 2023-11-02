#include "pch.h"
#include "MainWindow.h"
#include "MainWindow.g.cpp"

using namespace winrt;
using namespace Windows::UI;
using namespace Windows::UI::Text;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Media;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::HelloWinCode::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        TextBlock tb;
        tb.Text(L"Hello, Windows 10!");
        tb.FontFamily(FontFamily(L"Times New Roman"));
        tb.FontSize(216);
        tb.FontStyle(FontStyle::Italic);
        tb.Foreground(SolidColorBrush(Colors::Red()));
        tb.HorizontalAlignment(HorizontalAlignment::Center);
        tb.VerticalAlignment(VerticalAlignment::Center);
        contentGrid().Children().Append(tb);
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

}
