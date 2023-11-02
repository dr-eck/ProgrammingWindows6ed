#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <format>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::TapAndShowPoint::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    void MainWindow::OnTapped(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::Input::TappedRoutedEventArgs const& args)
    {
		Windows::Foundation::Point pt = args.GetPosition(sender.as<Microsoft::UI::Xaml::UIElement>());

		// create dot
		Microsoft::UI::Xaml::Shapes::Ellipse ellipse;
		ellipse.Width(3);
		ellipse.Height(3);
		ellipse.Fill(Microsoft::UI::Xaml::Media::SolidColorBrush(Microsoft::UI::Colors::Red()));
		canvas().SetLeft(ellipse, pt.X);
		canvas().SetTop(ellipse, pt.Y);
		canvas().Children().Append(ellipse);

		// create text
		Microsoft::UI::Xaml::Controls::TextBlock textBlock;
		int px = (int)(pt.X + 0.5);
		int py = (int)(pt.Y + 0.5);
		textBlock.Text(std::format(L"({},{})", px, py));
		textBlock.FontSize(24);
		Microsoft::UI::Xaml::Controls::Canvas::SetLeft(textBlock, pt.X);
		Microsoft::UI::Xaml::Controls::Canvas::SetTop(textBlock, pt.Y);
		canvas().Children().Append(textBlock);

		args.Handled(true);
    }

}
