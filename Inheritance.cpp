#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
	string Name;
	int SubscribersCount;
	list<string> PublishedVideoTitles;
protected:
	string OwnerName;
public:
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
	}
	void GetInfo() {
		cout << "Name: " << Name << endl;
		cout << "OwnerName: " << OwnerName << endl;
		cout << "SubscribersCount: " << SubscribersCount << endl;
		cout << "Videos: " << endl;
		for (string videoTitle : PublishedVideoTitles) {
			cout << videoTitle << endl;
		}
	}
	void Subscribe() {
		SubscribersCount++;
	}
	void Unsubscribe() {
		if (SubscribersCount > 0)
			SubscribersCount--;
	}
	void PublishVideo(string title) {
		PublishedVideoTitles.push_back(title);
	}
};

class OtherChannel: public YouTubeChannel {
private:
		string ChannelName;	
public: 
	OtherChannel(string channelname, string name, string ownerName):YouTubeChannel(name, ownerName)
	{
		ChannelName = channelname;
	}

	void info(){
		cout  << "This is Info for " <<  ChannelName << " channel of " << OwnerName << endl;
	}
};
//****************************************************
//******************   Main   ************************
//****************************************************
int main()
{
	YouTubeChannel ytCh("Rasoul's Channel", "Rasoul");
	ytCh.GetInfo();
	OtherChannel OthChan("Twiter", "John's Channel", "John");
	OthChan.info();
	OthChan.GetInfo();


	return 0;
}
