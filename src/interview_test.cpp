#include <iostream>
#include <set>

#include "subscriber.h"
#include "CableTV.h"

int main() {
  NewsSubscriber sub;
  // test NewsSubscriber
  sub.set_subscriber_name("one");
//  std::cout << sub.get_subscriber_name() << std::endl;

  sub.add_channel("x");
  sub.add_channel("y");
  sub.add_channel("z");
//  std::set <std::string> ch=sub.get_channels_names();
//  std::set<std::string>::iterator it;
//  for (it = ch.begin(); it != ch.end(); it++) {
//        std::cout << *it << '\n';
//    }

  //test cabletv

  CableTV cable(&sub);

  cable.Subscribe("one", "tx");
  cable.display();

//  NewsSubscriber sub2;
//  sub2.set_subscriber_name("two");
//  cable.add_Subscriber(&sub2);

  cable.Subscribe("two", "x");
  cable.display();

  cable.Subscribe("three", "x");
  cable.display();

  cable.OnNews("x", "ttttt");
  cable.display();

  cable.UnSubscribe("one", "tx");
  cable.display();

  cable.Subscribe("two", "ygy");
  cable.display();

  cable.UnSubscribeBySubscriber("one");
  cable.display();
//
  cable.UnSubscribeByChannel("x");
//
  cable.display();

  //std::cout << cable.number_of_user() << '\n';
  //cable.UnSubscribeBySubscriber("one");

  cable.OnNews("ygy", "fake2");

  return 0;
}
