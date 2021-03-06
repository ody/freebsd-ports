# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gps
PORTVERSION=	6.1.1.0
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	gps-6.1.1-src
PKGNAMESUFFIX=	-ide

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild>=20140417:${PORTSDIR}/devel/gprbuild \
		gnat_util>=20140422_2:${PORTSDIR}/lang/gnat_util \
		xmlada>=4.4:${PORTSDIR}/textproc/xmlada \
		gnatcoll>=2015:${PORTSDIR}/devel/gnatcoll \
		templates_parser>11:${PORTSDIR}/textproc/templates_parser
LIB_DEPENDS=	libgtkada.so:${PORTSDIR}/x11-toolkits/gtkada3
RUN_DEPENDS=	rsvg-convert:${PORTSDIR}/graphics/librsvg2 \
		gnatinspect:${PORTSDIR}/devel/gnatcoll \
		gdb${PORTGDB}:${PORTSDIR}/devel/gdb \
		${PYTHON_PKGNAMEPREFIX}pep8>0:${PORTSDIR}/devel/pep8 \
		${PYTHON_PKGNAMEPREFIX}jedi>0:${PORTSDIR}/devel/py-jedi

GNU_CONFIGURE=	yes
USES=		ada:run gmake perl5 pkgconfig python
USE_PERL5=	build
USE_GNOME=	glib20 pygobject3
PYCOMPILE=	${PREFIX}/lib/${PYTHON_VERSION}/compileall.py
AWKREVDATE=	'/Last Changed Date/ {print "\"s|unknown date|" $$4 "|\""}'
GPSVER=		GPS_VERSION=${PORTVERSION}
ALL_TARGET=	default
NO_MTREE=	yes
SUB_FILES=	gps
PORTGDB=	791

# note: librsvg2 is needed to display the svg icons in the menu.  Actually
# needed is lib/gdk-pixbuf-2.0/%%GTK2_VER%%/loaders/libpixbufloader-svg.so ,
# but it's a variable library needed only at runtime, which is obnoxious so
# we just request the sole binary to pull in the package which effectively
# accomplishes what is desired.

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx

CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-aux-${OPSYS:tl}${OSREL}
CONFIGURE_ENV+=		AWK=/usr/bin/awk
CONFIGURE_ARGS=		--with-gtk=3.0
MAKE_ARGS+=		PROCESSORS=${MAKE_JOBS_NUMBER}
MAKE_ARGS+=		PYTHON_CMD=${PYTHON_CMD}
PORTDOCS=		html pdf
PORTEXAMPLES=		demo python remote tutorial xml

.include <bsd.port.options.mk>

SUB_LIST=		ADA_PATH=${PREFIX}/${ADAXX}-aux/bin

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=		Build=Debug
.else
MAKE_ARGS+=		Build=Production
.endif

post-extract:
	@${MV} ${WRKSRC}/templates_parser ${WRKSRC}/TP.ignore
	@${MV} ${WRKSRC}/Makefile.gnat ${WRKSRC}/Makefile.gnat.ignore

post-patch:
	@${ECHO} "GNAT_SOURCES=" > ${WRKSRC}/Makefile.gnat
	@${REINPLACE_CMD} -e 's/^with .*templates_parser\//with "/g' \
		${WRKSRC}/gnatdoc/gnatdoc.gpr \
		${WRKSRC}/vcs/vcs.gpr
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' \
		${WRKSRC}/widgets/widgets.gpr
	#@${REINPLACE_CMD} -e 's|gnatlib/gnat_src|distrib|' \
	#	${WRKSRC}/distrib/from_impunit.pl
	@${REINPLACE_CMD} -e 's|, "-fdump-xref"||g' \
		${WRKSRC}/shared.gpr
	#@${REINPLACE_CMD} -e "s|GPS_VERSION=.*|${GPSVER}|" \
	#	${WRKSRC}/configure
	#@${AWK} ${AWKREVDATE} ${WRKSRC}/REVISION | ${XARGS} -I sub \
	#	${SED} -i.bak -e sub ${WRKSRC}/common/core/src/config.ads.in
	@${SED} -i '' -e \
		's|= "gnat"|= "${LOCALBASE}/${ADAXX}-aux/bin/gnat"|' \
		${WRKSRC}/share/support/core/gps_utils/gnat_rules.py
	#@${REINPLACE_CMD} -e 's|@UTILSHARE@|${LOCALBASE}/share/gnat_util|' \
	#	${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/gnatcoll_tools/d' ${WRKSRC}/gps/gps.gpr
	@${REINPLACE_CMD} -e 's|../gnatlib/src/||' \
		${WRKSRC}/common/comm* \
		${WRKSRC}/spark/spark.gpr \
		${WRKSRC}/kernel/kern*.gpr \
		${WRKSRC}/language/language.gpr \
		${WRKSRC}/vsearch/vsearch.gpr \
		${WRKSRC}/python/py*.gpr
	@${REINPLACE_CMD} -e '/Gdb_Command/ s|"gdb"|"gdb${PORTGDB}"|' \
		${WRKSRC}/gvd/src/debugger-gdb_mi.adb \
		${WRKSRC}/gvd/src/debugger-gdb.adb

do-build:
	@${CP} ${PREFIX}/include/gnat_util/impunit.* ${WRKSRC}/distrib
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} all
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/plug-ins
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/library

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/doc/gps/html/*/_sources
	${INSTALL_SCRIPT} ${WRKDIR}/gps ${STAGEDIR}${PREFIX}/bin
	echo "This is the GPS GPL Edition for the ${OPSYS} Ports Collection." \
		> ${STAGEDIR}${PREFIX}/share/gps/about.txt
	${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>
