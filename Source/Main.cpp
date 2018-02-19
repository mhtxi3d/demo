/**=============================================================================+
 * file name  : Main.cpp
 * created    : 2018.02.18
 * author     : sam
 * copyright  : Copyright(C) I3D Technology Inc. All rights reserved.
+=============================================================================*/
#include "../JuceLibraryCode/JuceHeader.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

const char kTestString[] = R"(
Adding driver package:  filter.inf
Driver package added successfully.
Published Name:         oem93.inf

Total driver packages:  1
Added driver packages:  1)";

String ExtractPnputilOutput(const String& raw, const String& key)
{
	return raw
		.fromFirstOccurrenceOf(key, false, true)
		.upToFirstOccurrenceOf("\n", false, true)
		.trimStart();
}

TEST_CASE("ExtractPnputilOutput")
{
	const auto r = ExtractPnputilOutput("Published Name:", kTestString);
	REQUIRE(r.equalsIgnoreCase("oem93.inf"));

	const auto r1 = ExtractPnputilOutput("Total driver packages:", kTestString);
	REQUIRE(r1.equalsIgnoreCase("1"));

	const auto r2 = ExtractPnputilOutput("Adding driver package:", kTestString);
	REQUIRE(r2.equalsIgnoreCase("filter.inf"));
}


//==============================================================================
//int main (int argc, char* argv[])
//{
//    return 0;
//}
