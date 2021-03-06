#include <iostream>
#include <set>

#include "subscriber.h"
#include "CableTV.h"

int main() {
  NewsSubscriber sub1("one");
  sub1.add_channel("x");
  sub1.add_channel("y");
  //sub2.add_channel("y");
  //sub2.add_channel("z");

  CableTV cable(&sub1);
  cable.Subscribe("two","y");
  cable.Subscribe("two","z");

  cable.OnNews("y","as");

  cable.OnNews("x","rt");
  cable.OnNews("z","das");

/*  // test NewsSubscriber
  std::cout  << "test NewsSubscriber\n\n";
  //sub.set_subscriber_name("one");
//  std::cout << sub.get_subscriber_name() << std::endl;

  sub.add_channel("x");
  sub.add_channel("y");
  sub.add_channel("z");
//  std::set <std::string> ch=sub.get_channels_names();
//  std::set<std::string>::iterator it;
//  for (it = ch.begin(); it != ch.end(); it++) {
//        std::cout << *it << ' ';
//  }

//  std::cout  << "\n\ntest cabletv";
  //test cabletv

  CableTV cable(&sub);
  cable.Subscribe("one", "tx");
//  cable.display();

//  NewsSubscriber sub2;
//  sub2.set_subscriber_name("two");
//  cable.add_Subscriber(&sub2);


  cable.Subscribe("two", "x");
//  cable.display();

  cable.Subscribe("three", "x");
//  cable.display();

  cable.OnNews("x", "ttttt");
//  cable.display();

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
*/
  return 0;
}
