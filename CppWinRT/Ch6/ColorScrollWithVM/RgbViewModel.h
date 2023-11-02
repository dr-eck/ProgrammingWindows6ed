#pragma once
#include "RgbViewModel.g.h"

namespace winrt::ColorScrollWithVM::implementation
{
    struct RgbViewModel : RgbViewModelT<RgbViewModel>
    {
        RgbViewModel();

        double Red();
        void Red(double value);
        double Green();
        void Green(double value);
        double Blue();
        void Blue(double value);
        Windows::UI::Color Color();
        void Color(Windows::UI::Color value);

        event PropertyChangedEventHandler PropertyChanged;

        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void RgbViewModel::PropertyChanged(winrt::event_token const& token) noexcept;

        void OnPropertyChanged(winrt::hstring const&);
        void Calculate();

        double red, green, blue;
        Windows::UI::Color color;
    };
}
namespace winrt::ColorScrollWithVM::factory_implementation
{
    struct RgbViewModel : RgbViewModelT<RgbViewModel, implementation::RgbViewModel>
    {
    };
}
