# $FreeBSD$

PORTNAME=               facter
PORTVERSION=            3.0.3.rc0
CATEGORIES=             sysutils
MASTER_SITES=           http://archive.home.herriges.org/

MAINTAINER=             cody@herriges.org
COMMENT=                Build of native C++ verion of Facter

LICENSE=                APACHE20

USES=                   cmake:outsource

BUILD_DEPENDS=          boost-libs>=1.54:${PORTSDIR}/devel/boost-libs \
                        yaml-cpp>=0.5.1:${PORTSDIR}/devel/yaml-cpp \
                        openssl>=0:${PORTSDIR}/security/openssl \
                        curl>=7.18.0:${PORTSDIR}/ftp/curl \
                        cmake>=3.2.2:${PORTSDIR}/devel/cmake \
                        ruby>=2.1.0:${PORTSDIR}/lang/ruby21

RUN_DEPENDS=            openssl>=0:${PORTSDIR}/security/openssl \
                        curl>=7.18.0:${PORTSDIR}/ftp/curl \
                        ruby>=2.1.0:${PORTSDIR}/lang/ruby21

.include <bsd.port.mk>
