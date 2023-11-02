#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
//using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Microsoft::UI;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Controls::Primitives;
using namespace Microsoft::UI::Xaml::Markup;
using namespace Microsoft::UI::Xaml::Data;
using namespace Microsoft::UI::Xaml::Input;
using namespace Microsoft::UI::Xaml::Media;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace Microsoft::UI::Xaml::Shapes;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PathMarkupSyntaxCode::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
 
        std::wstring str;
        str = L"M 0 0 L 0 100 M 0 50 L 50 50 M 50 0 L 50 100 ";
        str += L"M 125 0 C 60 -10, 60 60, 125 50, 60 40, 60 110, 125 100 ";
        str += L"M 150 0 L 150 100, 200 100 ";
        str += L"M 225 0 L 225 100, 275 100 ";
        str += L"M 300 50 A 25 50 0 1 0 300 49.9";
        Path path;
        path.Stroke(SolidColorBrush(Colors::Red()));
        path.StrokeThickness(12);
        path.StrokeLineJoin(PenLineJoin::Round);
        path.HorizontalAlignment(HorizontalAlignment::Center);
        path.VerticalAlignment(VerticalAlignment::Center);
        path.Data(PathMarkupToGeometry(str));

        //Grid().Children().Append(path); // This does not work!  It creates a new Grid rather than using the XAML grid.
        Content().try_as<Grid>().Children().Append(path);
    }

    Geometry MainWindow::PathMarkupToGeometry(const std::wstring& pathMarkup)
    {
        std::wstring xaml = L"<Path ";
        xaml += L"xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation'>";
        xaml += L"<Path.Data>";
        xaml += pathMarkup;
        xaml += L"</Path.Data></Path>";

        Path path = XamlReader::Load(xaml).try_as<Path>();  // N.B. use "try_as" to replace C# "as"
        Geometry geometry = path.Data();
        path.Data(nullptr); // detach the PathGeometry from the Path
        return geometry;
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
