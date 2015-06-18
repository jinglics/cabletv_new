#include <iostream>
#include <string>
#include <set>

#include "news.h"

class NewsSubscriber : public NewsSubscriberI {
	std::set<std::string> channel_names;
	std::string subscriber_name;
public:
  NewsSubscriber() {
  }
  NewsSubscriber(std::string name){
	  subscriber_name=name;
  }
  virtual ~NewsSubscriber() {}

public:
  void Publish(std::string subscriber_name, std::string content) {
    std::cout << "Received " << subscriber_name << ", ===" << content;
  }

  void set_subscriber_name(std::string name){
	  subscriber_name=name;
  }

  std::set<std::string> get_channels_names(){
	  return channel_names;
  }
  std::string get_subscriber_name(){
  	  return subscriber_name;
    }
  void add_channel(std::string channel_name){
	  channel_names.insert(channel_name);
  }
  void remove_channel(std::string channel_name){
  	  channel_names.erase(channel_name);
  }
  void remove_all_channel(){
	  channel_names.clear();
  }

};

