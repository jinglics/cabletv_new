#include <string>
#include <vector>
#include <map>

class CableTV : public NewsFeedI, public NewsPublisherI{
	std::vector<NewsSubscriber*> cabletv;
	std::map<std::string, std::string> channel_news;

public:
	CableTV(NewsSubscriber *sub):NewsPublisherI(sub){
		cabletv.clear();
		cabletv.push_back(sub);
	}

	virtual ~CableTV() {}

public:
	//test
	int number_of_user(){
		return cabletv.size();
	}
	void add_Subscriber(NewsSubscriber *sub){
		cabletv.push_back(sub);

	}

	void Subscribe(std::string subscriber_name, std::string channel_name) {
		bool exist=false;
		for(int i=0; i<cabletv.size(); i++){
			if(cabletv[i]->get_subscriber_name()==subscriber_name){
				cabletv[i]->add_channel(channel_name);
				exist=true;
			}
		}
		if(!exist){
			  NewsSubscriber *sub=new NewsSubscriber(subscriber_name);
			  //sub.set_subscriber_name(subscriber_name);
			  sub->add_channel(channel_name);
			  cabletv.push_back(sub);
		}
	}
	void UnSubscribe(std::string subscriber_name, std::string channel_name) {
		for(int i=0; i<cabletv.size(); i++){
			if(cabletv[i]->get_subscriber_name()==subscriber_name){
				cabletv[i]->remove_channel(channel_name);
			}
		}
	}
	    // remove all subscriptions under this subscriber
	void UnSubscribeBySubscriber(std::string subscriber_name) {
		for(int i=0; i<cabletv.size(); i++){
			if(cabletv[i]->get_subscriber_name()==subscriber_name){
				cabletv[i]->remove_all_channel();
			}
		}
	}
	    // remove all subscriptions under this channel
	void UnSubscribeByChannel(std::string channel_name) {
		for(int i=0; i<cabletv.size(); i++){
			cabletv[i]->remove_channel(channel_name);
		}
	}

	void OnNews(std::string channel_name, std::string news_content) {
		channel_news[channel_name]=news_content;
		for(int i=0; i<cabletv.size(); i++){
			std::set<std::string> tmp=cabletv[i]->get_channels_names();
			if(tmp.find(channel_name)!=tmp.end()){
				cabletv[i]->Publish(channel_name, news_content);
			}
		}
	}

	void display(){
		std::cout<<'\n';
		std::cout<<cabletv.size()<<'\n';
		for(int i=0; i<cabletv.size(); i++){
			std::cout << cabletv[i]->get_subscriber_name() << '\n';
			std::set<std::string> tmp=cabletv[i]->get_channels_names();
			std::set<std::string>::iterator it;
			for (it = tmp.begin(); it != tmp.end(); it++) {
			      std::cout << *it << ' ';
			}
			std::cout << '\n';
		}

		std::map<std::string, std::string>::iterator it;
		for (it = channel_news.begin(); it != channel_news.end(); it++) {
			std::cout << it->first << ' ' << it->second << '\n';
		}
	}
};
