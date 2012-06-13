/*
 * TestBundleList.h
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
#include <ibrdtn/data/BundleList.h>

#ifndef TESTBUNDLELIST_H_
#define TESTBUNDLELIST_H_

using namespace std;

class TestBundleList: public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (TestBundleList);
	CPPUNIT_TEST (orderTest);
	CPPUNIT_TEST (containTest);
	CPPUNIT_TEST_SUITE_END ();

public:
	void setUp (void);
	void tearDown (void);

protected:
	void orderTest(void);
	void containTest(void);

private:
	class DerivedBundleList : public dtn::data::BundleList
	{
	public:
		DerivedBundleList();
		virtual ~DerivedBundleList();

		void eventBundleExpired(const ExpiringBundle &b);

		int counter;
	};

	void genbundles(DerivedBundleList &l, int number, int offset, int max);

	DerivedBundleList *list;
};

#endif /* TESTBUNDLELIST_H_ */
