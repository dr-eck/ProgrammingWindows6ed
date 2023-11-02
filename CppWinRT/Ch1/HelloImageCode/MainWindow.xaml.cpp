#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Media;
using namespace Microsoft::UI::Xaml::Media::Imaging;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::HelloImageCode::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        Windows::Foundation::Uri uri(L"http://www.charlespetzold.com/pw6/PetzoldJersey.jpg");
        BitmapImage bmp(uri);
        Image img;
        img.Source(bmp);
        contentGrid().Children().Append(img);
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
