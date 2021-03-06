/*
**      ofxSQLite addon
**
**      Original Copyright (C) 2010 - 2012 Diederick Huijbers.
**                                          http://www.roxlu.com/
**                                          info@roxlu.com
**
**      ofxSQLiteDelete.cpp
**
**      ------------------------------------------------------------------------
**
**      The MIT License (MIT)
**
**      Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
**      associated documentation files (the "Software"), to deal in the Software without restriction,
**      including without limitation the rights to use, copy, modify, merge, publish, distribute,
**      sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
**      furnished to do so, subject to the following conditions:
**      The above copyright notice and this permission notice shall be included in all copies or
**      substantial portions of the Software.
**      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
**      BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
**      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
**      WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
**      OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "ofxSQLiteDelete.h"
#include "lib/sqlite/sqlite3.h"
#include <iostream>

ofxSQLiteDelete::ofxSQLiteDelete(sqlite3* pSQLite, std::string sTable):sqlite(pSQLite), table(sTable) {
}

std::string ofxSQLiteDelete::getLiteralQuery(bool bFillValues) {
	std::string sql = "DELETE FROM " +table +" ";
	if(wheres.size() > 0) {
		sql += wheres.getLiteralQuery(bFillValues);
	}
	return sql;
}

int ofxSQLiteDelete::execute() {
	std::string sql = getLiteralQuery();
	sqlite3_stmt* statement;
	if (SQLITE_OK != sqlite3_prepare_v2(sqlite, sql.c_str(),-1, &statement, 0)) {
		sqlite3_finalize(statement);
		return sqlite3_errcode(sqlite);
	}

	wheres.bind(statement);

	if (sqlite3_step(statement) != SQLITE_DONE) {
		sqlite3_finalize(statement);
		return sqlite3_errcode(sqlite);
	}

	sqlite3_finalize(statement);
	return SQLITE_OK;
}
