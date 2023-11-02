#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI;
using namespace Microsoft::UI::Text;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Media;
using namespace Microsoft::UI::Xaml::Controls;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::HelloApp::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        TextBlock txtblk;
        txtblk.Text(L"Hello, Windows 8");
        txtblk.FontFamily(FontFamily(L"Times New Roman"));
        txtblk.FontSize(96);
        txtblk.FontStyle(Windows::UI::Text::FontStyle::Italic);
        txtblk.Foreground(SolidColorBrush(Colors::Blue()));
        txtblk.HorizontalAlignment(HorizontalAlignment::Center);
        txtblk.VerticalAlignment(VerticalAlignment::Center);

        contentGrid().Children().Append(txtblk);
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
