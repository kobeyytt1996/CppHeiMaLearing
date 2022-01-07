#pragma once

#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

namespace widgetEnv {
	template<typename T>
	class WidgetImpl {

	};

	template<typename T>
	class Widget {
	public:
		void swap(Widget& rhs) {
			using std::swap;
			swap(pwi, rhs.pwi);
		}
	private:
		WidgetImpl<T>* pwi;
	};


	template<typename T>
	inline void swap(Widget<T>& lhs, Widget<T>& rhs) {
		cout << "yuan" << endl;
		lhs.swap(rhs);
	}
}
