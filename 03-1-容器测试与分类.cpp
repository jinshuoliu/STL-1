
/*
* 这里面包含了array、vector等容器的一些测试代码
*/

#include <iostream>
#include <string>
using namespace std;

long get_a_target_long()
	{
		long target = 0;

		// cout << "target (0~" << RAND_MAX << "):"; // 原来的RAND_MAX是32767，但是现在的RAND_MAX是2147483647，所以转换代码
    cout << "target (0~" << 32767 << "):";
		cin >> target;
		return target;
	}

string get_a_target_string()
	{
		long target = 0;
		char buf[10];

		// cout << "target (0~" << RAND_MAX << "):";
    cout << "target (0~" << 32767 << "):";
		cin >> target;
		// 把输入的数值转换为字符串
		snprintf(buf, 10, "%ld", target);
		return string(buf);
	}

// 比较long的大小
int compareLongs(const void* a, const void* b)
	{
		return (*(long*)a - *(long*)b);
	}

// 比较string的大小
int compareStrings(const void* a, const void* b)
	{
		cout << a << "," << b << endl;
		if (*(string*)a > *(string*)b)
			return 1;
		else if (*(string*)a < *(string*)b)
			return -1;
		else
			return 0;
	}

/*
#include <array>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
namespace leekarray {
#define ASIZE 50000

	void test_array()
	{
		cout << "\ntest_array()...........\n";
array<long, ASIZE> c;

clock_t timeStart = clock();
		for (long i = 0; i < ASIZE; ++i) {
			c[i] = rand();
		}

		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "array.size()= " << c.size() << endl;
		cout << "array.front()= " << c.front() << endl;
		// 返回数组在内存中的起始地址
		cout << "array.back()= " << c.back() << endl;
		cout << "array.data()= " << c.data() << endl;

long target = get_a_target_long();

		// 标记排序的起始时间，就是程序从运行到现在运行的时间
		timeStart = clock();
		// 排序：起始地址、元素数量、元素大小、排序规则
		qsort(c.data(), ASIZE, sizeof(long), compareLongs);
		// 查找
		long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
		// 输出这两个时间节点的距离（毫秒级），就是上面的排序和查找的动作所花费的时间
		cout << "qsort()+bsearch(), milli_seconds : " << (clock() - timeStart) << endl;

		if (pItem != NULL)
			cout << "found, " << *pItem << endl;
		else
			cout << "not found!" << endl;
	}
}
*/

/*
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
namespace leekvector {
	void test_vector(long& value) {
		cout << "\ntest_vector()..........\n";
	vector<string> c;
	char buf[10];
	clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try { // 防止内存不足
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		// 使用的空间
		cout << "vector.size()=" << c.size() << endl;
		cout << "vector.front()=" << c.front() << endl;
		cout << "vector.back()=" << c.back() << endl;
		cout << "vector.data()=" << c.data() << endl;
		// 容器真正占用的空间
		cout << "vector.capacity()=" << c.capacity() << endl;

	string target = get_a_target_string();
		{
			timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;

			if (pItem != c.end())
				cout << "found, " << *pItem << endl;
			else
				cout << "not found!" << endl;
		}

		timeStart = clock();
		sort(c.begin(), c.end());
	string* pItem = (string*)bsearch(&target, (c.data()),
			c.size(), sizeof(string), compareStrings);
		cout << "sort()+bsearch(),milli0seconds : " << (clock() - timeStart) << endl;

		if (pItem != NULL)
			cout << "found, " << *pItem << endl;
		else
			cout << "not found!" << endl;
	}
}
*/

/*
#include <list>
#include <iostream>
#include <algorithm>
namespace leeklist {
	void test_list(long& value) {
		cout << "\ntest_list()......\n";
	list<string> c;
	char buf[10];

	clock_t timeStart = clock();

		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			}
			catch (exception& p) {
				cout << "i" << i << " " << p.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds = " << (clock() - timeStart) << endl;
		cout << "list.size()" << c.size() << endl;
		cout << "list.max_size()" << c.max_size() << endl;
		cout << "list.front()" << c.front() << endl;
		cout << "list.back()" << c.back() << endl;

	string target = get_a_target_string();
		timeStart = clock();
	auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end())
			cout << "found, " << *pItem << endl;
		else
			cout << "not found!" << endl;

		timeStart = clock();
		c.sort();
		cout << "c.sort, milli-seconds : " << (clock() - timeStart) << endl;
		
	}
} 
*/

/*
#include <iostream>
#include <forward_list>
#include <algorithm>
namespace leekforward_list {
	void test_forward_list(long& value) {
		cout << "\ntest_forward_list()...........\n";

		forward_list<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_front(string(buf));
			}
			catch(exception & p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "forward_list.max_size()= " << c.max_size() << endl;
		cout << "forward_list.front()= " << c.front() << endl;
		//cout << "forward_list.back()= " << c.back() << endl;
		//cout << "forward_list.size()= " << c.size() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);

		cout << "::find(),milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end())
			cout << "found," << *pItem << endl;
		else
			cout << "not found!" << endl;

		timeStart = clock();
		c.sort();
		cout << "c.sort(),milli-seconds : " << (clock() - timeStart) << endl;
	}
}
*/

/* 这里visual不支持slist或者一些其他问题，我导入不进来包*/\
/*
#include <ext/slist>
#include <forward_list>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
namespace leekflist {
	void test_slist(long& value) {
		cout << "\ntest_slist().......\n";

		__gnu_cxx::slist<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for(long i=0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_front(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
			}
		}
		cout << "milli-seconds : " << (clock()-timeStart) << endl;
 	}
}
*/

/*
#include <deque>
#include <algorithm>
namespace leekdeque {
	void test_deque(long& value) {
		cout << "\ntest_deque().........\n";

		deque<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "deque.size()" << c.size() << endl;
		cout << "deque.front()" << c.front() << endl;
		cout << "deque.back()" << c.back() << endl;
		cout << "deque.max_size()" << c.max_size() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end())
			cout << "found, " << *pItem << endl;
		else
			cout << "not found!" << endl;

		timeStart = clock();
		::sort(c.begin(), c.end());
		cout << "::sort,milli-seconds : " << (clock() - timeStart) << endl;
	}
}
*/

/*
#include <algorithm>
#include <stack>
namespace leekstack {
	void test_stack(long& value) {
		cout << "\ntest_stack()..........\n";

		stack<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			}
			catch(exception& p){
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "stack.size()=" << c.size() << endl;
		cout << "stack.top()=" << c.top() << endl;
		c.pop();
		cout << "stack.size()=" << c.size() << endl;
		cout << "stack.top()=" << c.top() << endl;

	}
}
*/

/*
#include <algorithm>
#include <queue>
namespace leekqueue {
	void test_queue(long& value) {
		cout << "\ntest_queue()..........\n";

		queue<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "queue.size()=" << c.size() << endl;
		cout << "queue.front()=" << c.front() << endl;
		cout << "queue.back()=" << c.back() << endl;
		c.pop();
		cout << "queue.size()=" << c.size() << endl;
		cout << "queue.front()=" << c.front() << endl;
		cout << "queue.back()=" << c.back() << endl;

	}
}
*/


/*
#include <algorithm>
#include <set>
namespace leekmultiset {
	void test_multiset(long& value) {
		cout << "\test_multiset()..........\n";

		multiset<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				// 无序插入，按照它底层数据结构来安排位置
				c.insert(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}

		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "multiset.size()=" << c.size() << endl;
		cout << "multiset.max_size()=" << c.max_size() << endl;
		
		string target = get_a_target_string();
		{
			timeStart = clock();
      // 标准库的find
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found," << *pItem << endl;
			else
				cout << "not found!" << endl;
		}
		
		{
			timeStart = clock();
      // 容器本身的find，这个比较快
			auto pItem = c.find(target);
			cout << "c.find(),milli-seconds : " << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found," << *pItem << endl;
			else
				cout << "not found!" << endl;
		}
	}
}
*/

/*
#include <algorithm>
#include <map>
namespace leekmultimap{
  void test_multimap(long& value){
    cout << "\ntest_multimap()...........\n";

    multimap<long, string> c;
    char buf[10];
    clock_t timeStart = clock();
    for(long i = 0;i<value;++i){
      try{
        snprintf(buf, 10, "%d", rand());
        // multimap 不可以使用[] 作insertion
        c.insert(pair<long, string>(i, buf));
      }
      catch(exception& p){
          cout << "i=" << i << " " << p.what() << endl;
          abort();
      }
    }
    cout << "milli-seconds : " << (clock()-timeStart) <<endl;
    cout << "multimap.size()=" << c.size() << endl;
    cout << "multimap.max_size()=" << c.max_size() << endl;

    long target = get_a_target_long();
    timeStart = clock();
    auto pItem = c.find(target);
    cout << "c.find(),milli-seconds : " << (clock()-timeStart) <<endl;
    if(pItem!=c.end())
      cout << "found,value=" << (*pItem).second<<endl;
    else
      cout << "not found!" <<endl;
  }
}
*/

/*
#include <algorithm>
#include <unordered_set>
namespace leekhash_multiset{
  void test_hash_multiset(long& value){
    cout << "\ntest_hash_multiset().........\n";

    unordered_multiset<string> c;

    char buf[10];
    clock_t timeStart = clock();
    for(long i = 0;i<value;++i){
      try{
        snprintf(buf, 10, "%d", rand());
        // multimap 不可以使用[] 作insertion
        c.insert(string(buf));
      }
      catch(exception& p){
          cout << "i=" << i << " " << p.what() << endl;
          abort();
      }
    }
    cout << "milli-seconds : " << (clock()-timeStart) <<endl;
    cout << "unordered_multiset.size()=" << c.size() << endl;
    cout << "unordered_multiset.max_size()=" << c.max_size() << endl;
    cout << "unordered_multiset.bucket_count()=" << c.bucket_count() << endl;
    cout << "unordered_multiset.load_factor()=" << c.load_factor() << endl;
    cout << "unordered_multiset.max_load_factor()=" << c.max_load_factor() << endl;
    cout << "unordered_multiset.max_bucket_count()=" << c.max_bucket_count() << endl;
    
    for(unsigned i=0;i<20;++i){
      cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
    }
    
    string target = get_a_target_string();
    {
      timeStart = clock();
      auto pItem = ::find(c.begin(),c.end(), target);
      if(pItem!=c.end())
        cout << "found," << *pItem<<endl;
      else
        cout << "not found!" << endl;
    }
    {
      timeStart = clock();
      auto pItem = c.find(target);
      cout << "c.find(),milli-seconds : " << (clock()-timeStart) <<endl;
      if(pItem != c.end())
        cout << "found, " << *pItem << endl;
      else
        cout << "not found!" << endl;
    }
  }
}
*/

/*
#include <algorithm>
#include <unordered_map>
namespace leekhash_multimap{
  void test_hash_multimap(long& value){
    cout << "\ntest_hash_multimap().........\n";

    unordered_multimap<long, string> c;

    char buf[10];
    clock_t timeStart = clock();
    for(long i = 0;i<value;++i){
      try{
        snprintf(buf, 10, "%d", rand());
        // multimap 不可以使用[] 作insertion
        c.insert(pair<long,string>(i,buf));
      }
      catch(exception& p){
          cout << "i=" << i << " " << p.what() << endl;
          abort();
      }
    }
    cout << "milli-seconds : " << (clock()-timeStart) <<endl;
    cout << "unordered_multimap.size()=" << c.size() << endl;
    cout << "unordered_multimap.max_size()=" << c.max_size() << endl;
   
    
    for(unsigned i=0;i<20;++i){
      cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
    }
    
    long target = get_a_target_long();
    timeStart = clock();
    auto pItem = ::find(c.begin(),c.end(), target);
    if(pItem!=c.end())
      cout << "found," << (*pItem).second<<endl;
    else
      cout << "not found!" << endl;

  }
}
*/


/*
#include <algorithm>
#include <set>
namespace leekset{
  void test_set(long& value){
    cout << "\ntest_set().........\n";

    set<string> c;

    char buf[10];
    clock_t timeStart = clock();
    for(long i = 0;i<value;++i){
      try{
        snprintf(buf, 10, "%d", rand());
        c.insert(string(buf));
      }
      catch(exception& p){
          cout << "i=" << i << " " << p.what() << endl;
          abort();
      }
    }
    cout << "milli-seconds : " << (clock()-timeStart) <<endl;
    cout << "set.size()=" << c.size() << endl;
    cout << "set.max_size()=" << c.max_size() << endl;
    
    string target = get_a_target_string();
    {
      timeStart = clock();
      auto pItem = ::find(c.begin(),c.end(), target);
      if(pItem!=c.end())
        cout << "found," << *pItem<<endl;
      else
        cout << "not found!" << endl;
    }
    {
      timeStart = clock();
      auto pItem = c.find(target);
      cout << "c.find(),milli-seconds : " << (clock()-timeStart) <<endl;
      if(pItem != c.end())
        cout << "found, " << *pItem << endl;
      else
        cout << "not found!" << endl;
    }
  }
}
*/


/**/
#include <algorithm>
#include <map>
namespace leekmap{
  void test_map(long& value){
    cout << "\ntest_map().........\n";

    map<long, string> c;

    char buf[10];
    clock_t timeStart = clock();
    for(long i = 0;i<value;++i){
      try{
        snprintf(buf, 10, "%d", rand());
				// 在这里i和buf合成一个pair存放进去
        c[i]=string(buf);
      }
      catch(exception& p){
          cout << "i=" << i << " " << p.what() << endl;
          abort();
      }
    }
    cout << "milli-seconds : " << (clock()-timeStart) <<endl;
    cout << "map.size()=" << c.size() << endl;
    cout << "map.max_size()=" << c.max_size() << endl;
   
    long target = get_a_target_long();
    timeStart = clock();
    auto pItem = c.find(target);
    if(pItem!=c.end())
      cout << "found," << (*pItem).second<<endl;
    else
      cout << "not found!" << endl;

  }
}
/**/



int main() {
	//leekarray::test_array();

	long value = 1000000;
	// leekvector::test_vector(value);
	
	//leeklist::test_list(value);

	//leekforward_list::test_forward_list(value);

	//leekdeque::test_deque(value);

	// leekstack::test_stack(value);

	//leekmultiset::test_multiset(value);

  // leekmultimap::test_multimap(value);
  
  // leekhash_multiset::test_hash_multiset(value);

  // leekhash_multimap::test_hash_multimap(value);

	// leekset::test_set(value);

	leekmap::test_map(value);

	system("pause");
	return 0;
}
