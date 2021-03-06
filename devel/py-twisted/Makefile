# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twisted
PORTVERSION=	15.2.1
CATEGORIES=	devel net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Metaport of Twisted, an event-driven networking engine

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedCore>=${PORTVERSION}:${PORTSDIR}/devel/py-twistedCore

USES=		metaport python:2

# Bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	CONCH LORE MAIL NAMES NEWS PAIR RUNNER WEB WORDS
OPTIONS_DEFAULT=CONCH LORE MAIL NAMES NEWS PAIR RUNNER WEB WORDS
CONCH_DESC=	SSH and SFTP protocol
LORE_DESC=	Documentation generator
MAIL_DESC=	SMTP, IMAP and POP protocol
NAMES_DESC=	DNS protocol
NEWS_DESC=	NNTP protocol
PAIR_DESC=	Twisted Pair can do low level TCP work
RUNNER_DESC=	Process management
WEB_DESC=	HTTP protocol
WORDS_DESC=	Chat and Instant Messaging
CONCH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedConch>=${PORTVERSION}:${PORTSDIR}/security/py-twistedConch
LORE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedLore>=${PORTVERSION}:${PORTSDIR}/textproc/py-twistedLore
MAIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedMail>=${PORTVERSION}:${PORTSDIR}/mail/py-twistedMail
NAMES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedNames>=${PORTVERSION}:${PORTSDIR}/dns/py-twistedNames
NEWS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedNews>=${PORTVERSION}:${PORTSDIR}/news/py-twistedNews
PAIR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedPair>=${PORTVERSION}:${PORTSDIR}/net/py-twistedPair
RUNNER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedRunner>=${PORTVERSION}:${PORTSDIR}/devel/py-twistedRunner
WEB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedWeb>=${PORTVERSION}:${PORTSDIR}/www/py-twistedWeb
WORDS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedWords>=${PORTVERSION}:${PORTSDIR}/net-im/py-twistedWords

.include <bsd.port.mk>
