#include "pch.h"
#include "RgbViewModel.h"
#include "RgbViewModel.g.cpp"

using namespace winrt::Windows::UI;
using namespace winrt::Windows::UI::Xaml::Data;

namespace winrt::ColorScrollWithVM::implementation
{
    double RgbViewModel::Red()
    {
        return red;
    }
    void RgbViewModel::Red(double value)
    {
        if (red != value)
        {
            red = value;
            OnPropertyChanged(L"Red");
            Calculate();
        }
    }
    double RgbViewModel::Green()
    {
        return green;
    }
    void RgbViewModel::Green(double value)
    {
        if (green != value)
        {
            green = value;
            OnPropertyChanged(L"Green");
            Calculate();
        }
    }
    double RgbViewModel::Blue()
    {
        return blue;
    }
    void RgbViewModel::Blue(double value)
    {
        if (blue != value)
        {
            blue = value;
            OnPropertyChanged(L"Blue");
            Calculate();
        }
    }
    Windows::UI::Color RgbViewModel::Color()
    {
        return color;
    }
    void RgbViewModel::Color(Windows::UI::Color value)
    {
        if (color != value)
        {
            color = value;
            OnPropertyChanged(L"Color");
        }
    }
    winrt::event_token RgbViewModel::PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        throw hresult_not_implemented();
    }
    void RgbViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        throw hresult_not_implemented();
    }
    
    void RgbViewModel::OnPropertyChanged(winrt::hstring const& prop) // was winrt::event_token const& token) noexcept
    {
        if (PropertyChanged != null)
            PropertyChanged(PropertyChangedEventArgs(prop));
    }
    void RgbViewModel::Calculate()
    {
        color = ColorHelper::FromArgb(255, (uint8_t)red, (uint8_t)green, (uint8_t)blue);
    }
}
