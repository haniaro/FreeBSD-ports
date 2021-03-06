# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	bsddb3
PORTVERSION=	6.2.7
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python extension module for BerkeleyDB 4.7, 4.8, 5.1, 5.3, 6.1 and 6.2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		bdb python:3.6+
USE_PYTHON=	distutils autoplist

PYDISTUTILS_CONFIGUREARGS=--libs="-l${BDB_LIB_NAME}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_BUILDARGS=	--libs="-l${BDB_LIB_NAME}" --berkeley-db=${LOCALBASE}
PYDISTUTILS_INSTALLARGS=-c -O1 --prefix=${PREFIX} --berkeley-db=${LOCALBASE}

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's,%%DBVERSION%%,${BDB_LIB_NAME},g' ${WRKSRC}/setup2.py ${WRKSRC}/setup3.py
	@${REINPLACE_CMD} 's,<db\.h>,<${BDB_INCLUDE_DIR}/db.h>,' ${WRKSRC}/Modules/bsddb.h
	@${REINPLACE_CMD} 's,%%BDB_INCLUDE_DIR%%,${BDB_INCLUDE_DIR},' ${WRKSRC}/setup2.py ${WRKSRC}/setup3.py
	@${REINPLACE_CMD} 's,%%BDB_LIB_NAME%%,${BDB_LIB_NAME},' ${WRKSRC}/setup3.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bsddb3/_pybsddb*.so

.include <bsd.port.mk>
