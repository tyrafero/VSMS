//
// aboutus.xaml.cpp
// Implementation of the aboutus class
//

#include "pch.h"
#include "aboutus.xaml.h"
#include "MainPage.xaml.h"
#include "services.xaml.h"
#include "customer.xaml.h"
#include "staff.xaml.h"

using namespace App6;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

aboutus::aboutus()
{
	InitializeComponent();
}


void App6::aboutus::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(MainPage::typeid);
}


void App6::aboutus::Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(services::typeid);
}


void App6::aboutus::Button_Click_2(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(aboutus::typeid);
}
