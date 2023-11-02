#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
//#define USE_MATH_DEFINES
//#include <cmath>


using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::UI::Xaml::Shapes;
using namespace Windows::Foundation::Numerics;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Spiral::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        for (int angle = 0; angle < 3600; angle++) {
            float radians = float(angle * 3.12415926 / 180.0);
            float radius = float(angle) / 3.6f;
            float x = 1000 + radius * sin(radians);
            float y = 1000 + radius * cos(radians);
            polyline().Points().Append(float2(x, y));
        }
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
