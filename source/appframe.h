/*****************************************************************//**
 * @file   appframe.h
 * @brief  フレームワークのライブラリ指定
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#pragma comment(lib, "AppFrame.lib")

#include "Application/ApplicationBase.h"
#include "Application/InputOperation.h"
#include "Application/JoypadState.h"
#include "Data/Color.h"
#include "Mode/ModeBase.h"
#include "Mode/ModeServer.h"
#include "Server/ServerTemplateUnordered.h"
#include "Server/ServerTemplateVector.h"
#include "Math/Vector4.h"
#include "Math/Matrix44.h"
#include "Math/GravityBase.h"
#include "Math/Arithmetic.h"
#include "Math/Line.h"
#include "Math/Utility.h"