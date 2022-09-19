#pragma once
#include "../Observer/IObserver.h"
#include "IObservable.h"
#include <iostream>
#include <set>

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	using ObserverType = IObserver<T>;

	void RegisterObserver(ObserverType& observer) override
	{
		m_observers.insert(&observer);
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();

		// TODO: Как работет for range и итераторы
		// TODO: Скопировать m_observers и for range
		auto it = m_observers.begin();
		while (it != m_observers.end())
		{
			(*it)->Update(data);
			++it;
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{
		m_observers.erase(&observer);
	}

protected:
	// Классы-наследники должны перегрузить данный метод,
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;

private:
	std::set<ObserverType*> m_observers;
};