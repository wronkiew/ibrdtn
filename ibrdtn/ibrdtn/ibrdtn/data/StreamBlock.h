/*
 * StreamBlock.h
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

#ifndef STREAMBLOCK_H_
#define STREAMBLOCK_H_

#include "ibrdtn/data/SDNV.h"
#include "ibrdtn/data/Block.h"
#include "ibrdtn/data/ExtensionBlock.h"

namespace dtn
{
	namespace data
	{
		class StreamBlock : public dtn::data::Block
		{
		public:
			class Factory : public dtn::data::ExtensionBlock::Factory
			{
			public:
				Factory() : dtn::data::ExtensionBlock::Factory(StreamBlock::BLOCK_TYPE) {};
				virtual ~Factory() {};
				virtual dtn::data::Block* create();
			};

			static const char BLOCK_TYPE = 242;

			enum STREAM_FLAGS
			{
				STREAM_BEGIN = 1,
				STREAM_END = 1 << 0x01
			};

			StreamBlock();
			virtual ~StreamBlock();

			virtual size_t getLength() const;
			virtual std::ostream &serialize(std::ostream &stream, size_t &length) const;
			virtual std::istream &deserialize(std::istream &stream, const size_t length);

			void setSequenceNumber(size_t seq);
			size_t getSequenceNumber() const;

			void set(STREAM_FLAGS flag, const bool &value);
			bool get(STREAM_FLAGS flag) const;

		private:
			dtn::data::SDNV _seq;
			size_t _streamflags;
		};

		/**
		 * This creates a static block factory
		 */
		static StreamBlock::Factory __StreamBlockFactory__;
	} /* namespace data */
} /* namespace dtn */
#endif /* STREAMBLOCK_H_ */
