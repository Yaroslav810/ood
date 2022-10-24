#include "lib/Beverages/Coffee/Cappuccino/CCappuccino.h"
#include "lib/Beverages/Coffee/Latte/CLatte.h"
#include "lib/Condiments/Chocolate/CChocolate.h"
#include "lib/Condiments/Cream/CCream.h"
#include "lib/Condiments/Liquor/CLiquor.h"
#include <iostream>
#include <memory>

int main()
{
	{
		auto latte = std::make_unique<CLatte>(LatteSize::Standard);
		std::cout << latte->GetDescription() << " costs " << latte->GetCost() << std::endl;
		auto latteWithCream = std::make_unique<CCream>(std::move(latte));
		std::cout << latteWithCream->GetDescription() << " costs " << latteWithCream->GetCost() << std::endl;
	}

	{
		auto latte = std::make_unique<CLatte>(LatteSize::Standard);
		std::cout << latte->GetDescription() << " costs " << latte->GetCost() << std::endl;
		auto latteWithOneChocolate = std::make_unique<CChocolate>(std::move(latte), 1);
		std::cout << latteWithOneChocolate->GetDescription() << " costs " << latteWithOneChocolate->GetCost() << std::endl;
		auto latteWithManyChocolate = std::make_unique<CChocolate>(std::move(latteWithOneChocolate), 2);
		std::cout << latteWithManyChocolate->GetDescription() << " costs " << latteWithManyChocolate->GetCost() << std::endl;
	}

	{
		auto latte = std::make_unique<CLatte>(LatteSize::Standard);
		std::cout << latte->GetDescription() << " costs " << latte->GetCost() << std::endl;
		auto latteWithNuttyLiquor = std::make_unique<CLiquor>(std::move(latte), LiquorTaste::Nutty);
		std::cout << latteWithNuttyLiquor->GetDescription() << " costs " << latteWithNuttyLiquor->GetCost() << std::endl;
	}

	{
		auto latte = std::make_unique<CLatte>(LatteSize::Standard);
		std::cout << latte->GetDescription() << " costs " << latte->GetCost() << std::endl;
		auto latteWithChocolateLiquor = std::make_unique<CLiquor>(std::move(latte), LiquorTaste::Chocolate);
		std::cout << latteWithChocolateLiquor->GetDescription() << " costs " << latteWithChocolateLiquor->GetCost() << std::endl;
	}

	return 0;
}
