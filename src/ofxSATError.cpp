/*
**      ARTSAT Project
**
**      Original Copyright (C) 2011 - 2012 HORIGUCHI Junshi.
**                                          http://iridium.jp/
**                                          zap00365@nifty.com
**      Portions Copyright (C) <year> <author>
**                                          <website>
**                                          <e-mail>
**      Version     openFrameworks
**      Website     http://artsat.jp/
**      E-mail      info@artsat.jp
**
**      This source code is for Xcode.
**      Xcode 4.2 (LLVM compiler 3.0)
**
**      ofxSATError.cpp
**
**      ------------------------------------------------------------------------
**
**      THE SOURCE CODE AND THE BINARY OF ARTSAT API IS DISTRIBUTED UNDER THE MIT LICENSE WRITTEN BELOW.
**      THE LICENSE OF ANY DATA GOTTEN THROUGH ARTSAT API FOLLOWS PROVIDED LICENSE ON EACH SATELLITE.
**
**      ARTSAT API のソースコードとバイナリは下記に示す MIT ライセンスの元で配布されます。
**      ARTSAT API を通して取得できるデータのライセンスに関してはデータの提供元となる各衛星の定めるライセンスに準じます。
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
**
**      以下に定める条件に従い、本ソフトウェアおよび関連文書のファイル（以下「ソフトウェア」）の複製を
**      取得するすべての人に対し、ソフトウェアを無制限に扱うことを無償で許可します。
**      これには、ソフトウェアの複製を使用、複写、変更、結合、掲載、頒布、サブライセンス、および、または販売する権利、
**      およびソフトウェアを提供する相手に同じことを許可する権利も無制限に含まれます。
**      上記の著作権表示および本許諾表示を、ソフトウェアのすべての複製または重要な部分に記載するものとします。
**      ソフトウェアは「現状のまま」で、明示であるか暗黙であるかを問わず、何らの保証もなく提供されます。
**      ここでいう保証とは、商品性、特定の目的への適合性、および権利非侵害についての保証も含みますが、それに限定されるものではありません。
**      作者または著作権者は、契約行為、不法行為、またはそれ以外であろうと、ソフトウェアに起因または関連し、
**      あるいはソフトウェアの使用またはその他の扱いによって生じる一切の請求、損害、その他の義務について何らの責任も負わないものとします。
*/

#include "ofxSATError.h"

/*public */std::string ofxSATError::print(void) const
{
    char result[64] = "\0";
    
    switch (_error) {
        case SATERROR_OK:
            snprintf(result, sizeof(result), "%d (SATERROR_OK)", _error);
            break;
        case SATERROR_FAILED:
            snprintf(result, sizeof(result), "%d (SATERROR_FAILED)", _error);
            break;
        case SATERROR_NO_SUPPORT:
            snprintf(result, sizeof(result), "%d (SATERROR_NO_SUPPORT)", _error);
            break;
        case SATERROR_NO_RESULT:
            snprintf(result, sizeof(result), "%d (SATERROR_NO_RESULT)", _error);
            break;
        case SATERROR_NO_MEMORY:
            snprintf(result, sizeof(result), "%d (SATERROR_NO_MEMORY)", _error);
            break;
        case SATERROR_INVALID_PARAM:
            snprintf(result, sizeof(result), "%d (SATERROR_INVALID_PARAM)", _error);
            break;
        case SATERROR_INVALID_STATE:
            snprintf(result, sizeof(result), "%d (SATERROR_INVALID_STATE)", _error);
            break;
        case SATERROR_INVALID_FORMAT:
            snprintf(result, sizeof(result), "%d (SATERROR_INVALID_FORMAT)", _error);
            break;
        case SATERROR_WAIT_RESULT:
            snprintf(result, sizeof(result), "%d (SATERROR_WAIT_RESULT)", _error);
            break;
        case SATERROR_NETWORK_DOWN:
            snprintf(result, sizeof(result), "%d (SATERROR_NETWORK_DOWN)", _error);
            break;
        case SATERROR_NETWORK_CODE:
            snprintf(result, sizeof(result), "%d (SATERROR_NETWORK_CODE)", _error);
            break;
        default:
            snprintf(result, sizeof(result), "%d (unknown error)", _error);
            break;
    }
    return result;
}
