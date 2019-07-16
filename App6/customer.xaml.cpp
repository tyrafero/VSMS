//
// customer.xaml.cpp
// Implementation of the customer class
//

#include "pch.h"
#include "customer.xaml.h"
#include "MainPage.xaml.h"
#include "services.xaml.h"
#include "staff.xaml.h"
#include "aboutus.xaml.h"

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

using namespace Windows::Storage;
using namespace concurrency;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

customer::customer()
{
	InitializeComponent();
}


void App6::customer::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(MainPage::typeid);
}


void App6::customer::Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(services::typeid);
}


void App6::customer::Button_Click_2(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(aboutus::typeid);
}


void App6::customer::Button_Click_3(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(staff::typeid);
}



void App6::customer::Button_Click_4(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(customer::typeid);
}

void App6::customer::Button_Click_5(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Platform::String^ savingData = userName->Text + "\t" + carModel->Text + "\t" + carRegNo->Text + "\t" + userContact->Text + "\n";
	saveFile(savingData);

}

static Platform::String^ saveData;

int customer::saveFile(Platform::String^ toSave) {
	saveData = toSave;
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	create_task(storageFolder->CreateFileAsync("customerDetails.txt", CreationCollisionOption::OpenIfExists)).then([&](StorageFile^ sampleFile) {
		create_task(FileIO::AppendTextAsync(sampleFile, saveData + "\n"));
	});
	return 0;
}




