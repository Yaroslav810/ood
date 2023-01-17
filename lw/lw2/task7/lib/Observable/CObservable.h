#pragma once
#include "../Observer/IObserver.h"
#include "IObservable.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

// Реализация интерфейса IObservable
template <class T, class Indicator>
class CObservable : public IObservable<T, Indicator>
{
public:
	using ObserverType = IObserver<T, Indicator>;

	void RegisterObserver(ObserverType& observer, Indicator indicator) override
	{
		RemoveObserver(observer);
		m_observers.insert(std::make_pair(indicator, &observer));
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		std::set<Indicator> indicators = GetIndicatorsData();

		auto observers = m_observers;
		for (auto it = observers.rbegin(); it != observers.rend(); ++it)
		{
			if (indicators.contains(it->first))
			{
				it->second->Update(data, it->first); // TODO: Можно передать Indicator
			}
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
	virtual std::set<Indicator> GetIndicatorsData() const = 0;

private:
	std::multimap<Indicator, ObserverType*> m_observers;
};
