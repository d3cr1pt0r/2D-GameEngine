#pragma once

#include <vector>

#include "../Singleton.h"
#include "BaseManager.h"

namespace Engine {

	class ManagerSystem : public Singleton<ManagerSystem> {

	public:
		void onCreate() override;
		void onDestroy() override;

		template <class T>
		inline void registerManager() {
			BaseManager* manager = new T();
			managers_.push_back(manager);
		}

		inline void unregisterManagers() {
			for (unsigned i = managers_.size(); i-- > 0;) {
				delete managers_[i];
			}

			managers_.clear();
		}

	private:
		std::vector<BaseManager*> managers_;
	};
}