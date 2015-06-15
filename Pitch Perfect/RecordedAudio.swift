//
//  RecordedAudio.swift
//  Pitch Perfect
//
//  Created by Oleg Trofimov on 6/7/15.
//  Copyright (c) 2015 Oleg Trofimov. All rights reserved.
//

import Foundation

class RecordedAudio: NSObject {
    var filePathUrl: NSURL!
    var title: String!

    init(filePathUrl: NSURL, title: String) {
        self.filePathUrl = filePathUrl
        self.title = title
    }
}