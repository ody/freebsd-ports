# Created by: Konstantin Tokarev <annulen@yandex.ru>
# $FreeBSD$

PORTNAME=	openpref
PORTVERSION=	0.1.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/OpenPref-Qt4/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	annulen@yandex.ru
COMMENT=	Preferans game

LICENSE=	GPLv3

USES=		qmake
USE_QT4=	corelib gui moc_build rcc_build uic_build
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/i18n/${PORTNAME}_ru.qm \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRS=	%%DATADIR%%/i18n %%DATADIR%%

PORTDOCS=	AUTHORS BUGS NEWS README THANKS
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="OpenPref" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;CardGame;" ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}/i18n
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_ru.qm ${STAGEDIR}${DATADIR}/i18n/
	${INSTALL_DATA} ${WRKSRC}/pics/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
