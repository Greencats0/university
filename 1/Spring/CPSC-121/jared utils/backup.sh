#!/usr/bin/env bash
DATE=`date +%Y-%m-%d`
mkdir -p /media/jared/External/backup/"$DATE"
cd /media/jared/External/backup/"$DATE"
tar -czf Desktop.tar.gz ~/Desktop/*
tar -czf vmware.tar.gz ~/vmware/*
tar -czf exportme.tar.gz ~/export-me/*
tar -czf preferences.tar.gz ~/preferences/*
tar -czf shsh2_blobs.tar.gz ~/shsh2_blobs/*
