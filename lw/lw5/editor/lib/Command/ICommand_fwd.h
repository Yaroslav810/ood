#pragma once
#include "ICommand.h"
#include <iostream>
#include <memory>

using ICommandPtr = std::unique_ptr<ICommand>;
