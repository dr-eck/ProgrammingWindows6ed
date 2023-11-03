// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Windows::Storage;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Streams;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PrimitivePad2::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    winrt::fire_and_forget MainWindow::OnFileOpenButtonClick(Windows::Foundation::IInspectable const& , Microsoft::UI::Xaml::RoutedEventArgs const& )
    {
        // from https://learn.microsoft.com/en-us/windows/apps/develop/ui-input/display-ui-objects#winui-3-with-c
        FileOpenPicker picker;

        // Retrieve the window handle (HWND) of the current WinUI 3 window.
        // from https://learn.microsoft.com/en-us/windows/apps/develop/ui-input/retrieve-hwnd#winui-3-with-c-1
        auto windowNative{ this->m_inner.as<::IWindowNative>() };
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);

        // Initialize the folder picker with the window handle (HWND).
        auto initializeWithWindow{ picker.as<::IInitializeWithWindow>() };
        initializeWithWindow->Initialize(hWnd);

        // Use the folder picker as usual.
        picker.FileTypeFilter().Append(L"*");
        StorageFile ifile{ co_await picker.PickSingleFileAsync() };

		// If user presses Cancel, result is null
		if (ifile == nullptr)
			co_return;

        // from https://learn.microsoft.com/en-us/windows/uwp/files/quickstart-reading-and-writing-files
        winrt::hstring text{ co_await Windows::Storage::FileIO::ReadTextAsync(ifile) };
        txtbox().Text(text);
    }

    winrt::fire_and_forget MainWindow::OnFileSaveAsButtonClick(Windows::Foundation::IInspectable const& , Microsoft::UI::Xaml::RoutedEventArgs const& )
    {
         FileSavePicker picker;

         // from https://github.com/microsoft/Windows-universal-samples/blob/main/Samples/FilePicker/cppwinrt/Scenario4_SaveFile.cpp
         picker.SuggestedStartLocation(PickerLocationId::DocumentsLibrary);
         // Dropdown of file types the user can save the file as
         picker.FileTypeChoices().Insert(L"Plain Text", single_threaded_vector<hstring>({ L".txt" }));
         // Default file name if the user does not type one in or select a file to replace
         picker.SuggestedFileName(L"New Document");

        // Retrieve the window handle (HWND) of the current WinUI 3 window.
        auto windowNative{ this->m_inner.as<::IWindowNative>() };
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);

        // Initialize the folder picker with the window handle (HWND).
        auto initializeWithWindow{ picker.as<::IInitializeWithWindow>() };
        initializeWithWindow->Initialize(hWnd);

        // Use the folder picker as usual.
        StorageFile storageFile{ co_await picker.PickSaveFileAsync() };

        // If user presses Cancel, result is null
        if (storageFile == nullptr)
            co_return;

        // from https://learn.microsoft.com/en-us/windows/uwp/files/quickstart-reading-and-writing-files
        co_await Windows::Storage::FileIO::WriteTextAsync(storageFile, txtbox().Text());
    }

    winrt::fire_and_forget MainWindow::OnWrapButtonChecked(Windows::Foundation::IInspectable const& , Microsoft::UI::Xaml::RoutedEventArgs const& )
    {
        return winrt::fire_and_forget();
    }
}
