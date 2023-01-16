#pragma once
#include "../Observer/IObserver.h"
#include "IObservable.h"
#include <algorithm>
#include <iostream>
#include <map>

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	using ObserverType = IObserver<T>;

	void RegisterObserver(ObserverType& observer, int priority) override
	{
		RemoveObserver(observer);
		m_observers.insert(std::make_pair(priority, &observer));
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();

		auto observers = m_observers;
		for (auto it = observers.rbegin(); it != observers.rend(); ++it)
		{
			it->second->Update(data, *this);
		}
	}
	
	void RemoveObserver(ObserverType& observer) override
	{
		auto i = std::find_if(m_observers.begin(), m_observers.end(), [&](auto& it) {
			return it.second == &observer;
		});
		if (i != m_observers.end())
		{
			m_observers.erase(i->first);
		}
	}

protected:
	// Классы-наследники должны перегрузить данный метод,
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;

private:
	std::multimap<int, ObserverType*> m_observers;
};
