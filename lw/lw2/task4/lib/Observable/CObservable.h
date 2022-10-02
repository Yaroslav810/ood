#pragma once
#include "../Observer/IObserver.h"
#include "IObservable.h"
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
		for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			if (it->second == &observer)
			{
				m_observers.erase(it->first);
				break;
			}
		}
	}

protected:
	// Классы-наследники должны перегрузить данный метод,
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;

private:
	std::map<int, ObserverType*> m_observers;
};
