#include "lib/Beverages/Coffee/Cappuccino/CCappuccino.h"
#include "lib/Beverages/Coffee/Latte/CLatte.h"
#include "lib/Beverages/Milkshake/CMilkshake.h"
#include "lib/Beverages/Tea/CTea.h"
#include <iostream>
#include <memory>

int main()
{
	auto latteStandard = std::make_unique<CLatte>(LatteType::Standard);
	std::cout << latteStandard->GetDescription() << " costs " << latteStandard->GetCost() << std::endl;
	auto latteDouble = std::make_unique<CLatte>(LatteType::Double);
	std::cout << latteDouble->GetDescription() << " costs " << latteDouble->GetCost() << std::endl;

	auto cappuccinoStandard = std::make_unique<CCappuccino>(CappuccinoType::Standard);
	std::cout << cappuccinoStandard->GetDescription() << " costs " << cappuccinoStandard->GetCost() << std::endl;
	auto cappuccinoDouble = std::make_unique<CCappuccino>(CappuccinoType::Double);
	std::cout << cappuccinoDouble->GetDescription() << " costs " << cappuccinoDouble->GetCost() << std::endl;

	auto teaBlack = std::make_unique<CTea>(TeaType::Black);
	std::cout << teaBlack->GetDescription() << " costs " << teaBlack->GetCost() << std::endl;
	auto teaOolong = std::make_unique<CTea>(TeaType::Oolong);
	std::cout << teaOolong->GetDescription() << " costs " << teaOolong->GetCost() << std::endl;
	auto teaPuer = std::make_unique<CTea>(TeaType::Puer);
	std::cout << teaPuer->GetDescription() << " costs " << teaPuer->GetCost() << std::endl;
	auto teaEarlGrey = std::make_unique<CTea>(TeaType::EarlGrey);
	std::cout << teaEarlGrey->GetDescription() << " costs " << teaEarlGrey->GetCost() << std::endl;

	auto milkshakeSmall = std::make_unique<CMilkshake>(MilkshakeType::Small);
	std::cout << milkshakeSmall->GetDescription() << " costs " << milkshakeSmall->GetCost() << std::endl;
	auto milkshakeMedium = std::make_unique<CMilkshake>(MilkshakeType::Medium);
	std::cout << milkshakeMedium->GetDescription() << " costs " << milkshakeMedium->GetCost() << std::endl;
	auto milkshakeBig = std::make_unique<CMilkshake>(MilkshakeType::Big);
	std::cout << milkshakeBig->GetDescription() << " costs " << milkshakeBig->GetCost() << std::endl;

	return 0;
}
