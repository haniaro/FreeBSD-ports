# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	composer
DISTVERSION=	2.0.8
CATEGORIES=	devel
MASTER_SITES=	https://getcomposer.org/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2
DISTNAME=	composer
EXTRACT_SUFX=	.phar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Dependency Manager for PHP, version 2.x

LICENSE=	MIT

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		php:flavors
USE_PHP=	intl openssl phar json ctype filter mbstring

CONFLICTS_INSTALL=	php*-composer-*

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/composer \
		bin/composer.phar

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${_DISTDIR}/composer.phar ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/composer.phar ${STAGEDIR}${PREFIX}/bin/
	${LN} -s composer.phar ${STAGEDIR}${PREFIX}/bin/composer

.include <bsd.port.mk>
