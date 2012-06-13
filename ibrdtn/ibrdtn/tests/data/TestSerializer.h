/*
 * TestSerializer.h
 *
 *   Copyright 2011 Johannes Morgenroth
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#ifndef TESTSERIALIZER_H_
#define TESTSERIALIZER_H_

class TestSerializer : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (TestSerializer);
	CPPUNIT_TEST (serializer_separate01);
	CPPUNIT_TEST (serializer_cbhe01);
	CPPUNIT_TEST (serializer_cbhe02);
	CPPUNIT_TEST (serializer_bundle_length);
	CPPUNIT_TEST (serializer_fragment_one);
	CPPUNIT_TEST_SUITE_END ();

public:
	void setUp (void);
	void tearDown (void);

protected:
	void serializer_separate01(void);
	void serializer_cbhe01(void);
	void serializer_cbhe02(void);

	void serializer_bundle_length(void);

	void serializer_fragment_one(void);
};

#endif /* TESTSERIALIZER_H_ */
