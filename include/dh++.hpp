/***************************************************************
 * file:	include/dh++.hpp
 *************************************************************** */

#ifndef DHPP_H

#define DHPP_H
#define LIBDHPP
#define LIBDHPP_VERSION 0
#define LIBDHPP_RELEASE 1
#define LIBDHPP_REV_DATE 20110826
#define LIBDHPP_REV_NUM 298

namespace libDH
{

const int dhpp_version = LIBDHPP_VERSION;
const int dhpp_release = LIBDHPP_RELEASE;
const int dhpp_rev_date = LIBDHPP_REV_DATE;
const int dhpp_rev_num = LIBDHPP_REV_NUM;

class DHMain
{

private:
	DHMain();
	DHMain(const DHMain& dhminst);
	virtual ~DHMain();

};

}

#endif

