//
// staff.xaml.cpp
// Implementation of the staff class
//

#include "pch.h"
#include "staff.xaml.h"
#include "MainPage.xaml.h"
#include "services.xaml.h"
#include "customer.xaml.h"
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

staff::staff()
{
	InitializeComponent();
}


void App6::staff::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(MainPage::typeid);
}


void App6::staff::Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(services::typeid);
}


void App6::staff::Button_Click_2(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(aboutus::typeid);
}


void App6::staff::Button_Click_3(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(staff::typeid);
}



void App6::staff::Button_Click_4(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(customer::typeid);
}

static Platform::String^ username;
static Platform::String^ password;

void App6::staff::StaffRegisterBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	saveFile(staffUsername->Text, staffPassword->Password);
}

int staff::saveFile(Platform::String^ userNme, Platform::String^ passWrd) {
	username = userNme;
	password = passWrd;
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	create_task(storageFolder->CreateFileAsync("staffDetails.txt", CreationCollisionOption::OpenIfExists)).then([&](StorageFile^ sampleFile) {
		create_task(FileIO::AppendTextAsync(sampleFile, username + "\t" + password + "\n"));
		});
	return 0;
}

void App6::staff::StaffLoginBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	/*username = staffUsername->Text;
	password = staffPassword->Password;
	StorageFolder^ folder = ApplicationData::Current->LocalFolder;
	create_task(folder->GetFileAsync("staffDetails.txt")).then([](StorageFile^ fileInFolder) {
		return FileIO::ReadTextAsync(fileInFolder);
	}).then([&](Platform::String^ s) {
		int i = 0;
		std::string links[100];
		std::wstring strBuffer(s->Begin());
		std::string normalStr(strBuffer.begin(), strBuffer.end());
		std::string::iterator it = normalStr.begin();
		while (it != normalStr.end()) {
			if (*it == '\n') {
				i++;
			} else {
				links[i].push_back(*it);
			}
			it++;
		}
		i--;
	});*/
}
