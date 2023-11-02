#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Media;
using namespace Windows::Foundation::Numerics;


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::GradientBrushCode::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        // Create the foreground brush for the TextBlock
        LinearGradientBrush fgb;
        fgb.StartPoint(float2(0, 0));
        fgb.EndPoint(float2(1, 0));

        GradientStop gs0;
        gs0.Offset(0);
        gs0.Color(Colors::Blue());
        fgb.GradientStops().Append(gs0);

        GradientStop gs1;
        gs1.Offset(1);
        gs1.Color(Colors::Red());
        fgb.GradientStops().Append(gs1);

        txtblk().Foreground(fgb);

        // Create a background brush for the Grid
        LinearGradientBrush bgb;
        bgb.StartPoint(float2(0, 0));
        bgb.EndPoint(float2(1, 0));

        GradientStop gs2;
        gs2.Offset(0);
        gs2.Color(Colors::Red());
        bgb.GradientStops().Append(gs2);

        GradientStop gs3;
        gs3.Offset(1);
        gs3.Color(Colors::Blue());
        bgb.GradientStops().Append(gs3);

        contentGrid().Background(bgb);
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
