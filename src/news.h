#include <vector>
#include <string>

class NewsSubscriberI {
public:
  NewsSubscriberI() {}
  virtual ~NewsSubscriberI() {}

public:
  virtual void Publish(std::string subscriber_name, std::string content) = 0;
};

class NewsFeedI {
public:
  NewsFeedI() {}
  virtual ~NewsFeedI() {}

public:
  virtual void OnNews(std::string channel_name, std::string news_content) = 0;
};

class NewsPublisherI {
public:
  NewsPublisherI(NewsSubscriberI* subscriber) {}
  virtual ~NewsPublisherI() {}

  void InitializeChannels(std::vector<std::string> channel_names);

public:
  virtual void Subscribe(std::string subscriber_name, std::string channel_name) = 0;
  virtual void UnSubscribe(std::string subscriber_name, std::string channel_name) = 0;
  // remove all subscriptions under this subscriber
  virtual void UnSubscribeBySubscriber(std::string subscriber_name) = 0;
  // remove all subscriptions under this channel
  virtual void UnSubscribeByChannel(std::string channel_name) = 0;
};
