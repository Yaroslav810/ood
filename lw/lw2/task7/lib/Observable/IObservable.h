#pragma once

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T, typename Indicator>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T, Indicator>& observer, Indicator indicator) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T, Indicator>& observer) = 0;
};