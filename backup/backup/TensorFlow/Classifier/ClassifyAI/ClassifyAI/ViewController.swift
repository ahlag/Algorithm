//
//  ViewController.swift
//  ClassifyAI
//
//  Created by HIROKI INOUE on 2019/01/05.
//  Copyright © 2019年 eEducation Labs. All rights reserved.
//

import UIKit
import CoreML
import Vision

class ViewController: UIViewController, UIImagePickerControllerDelegate, UINavigationControllerDelegate {

    @IBOutlet weak var imageDisplay: UIImageView!
    @IBOutlet weak var predictionDisplay: UITextView!
    var imagePicker: UIImagePickerController!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        imagePicker = UIImagePickerController()
        imagePicker.delegate = self
        imagePicker.sourceType = .camera
    }

    @IBAction func takePhoto(_ sender: Any) {
        present(imagePicker, animated: true, completion: nil)
    }
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
        imageDisplay.image = info[UIImagePickerController.InfoKey.originalImage] as? UIImage
        imagePicker.dismiss(animated: true, completion: nil)
        imagePrediction(image: (info[UIImagePickerController.InfoKey.originalImage] as? UIImage)!)
    }
    
    func imagePrediction(image: UIImage) {
        guard let model = try? VNCoreMLModel(for: animal_cnn_aug().model) else {
            fatalError("Model not found")
        }
        
        let request = VNCoreMLRequest(model: model) {
            [weak self] request, error in
            
            guard let results = request.results as? [VNClassificationObservation],
                let firstResult = results.first else {
                    fatalError("No results found")
            }
            
            DispatchQueue.main.async {
                self?.predictionDisplay.text = "Accuracy: = \(Int(firstResult.confidence * 100))% \n\nラベル: \((firstResult.identifier))"
            }
        }
        
        guard let ciImage = CIImage(image: image) else {
            fatalError("Can't convert image.")
        }
        
        let imageHandler = VNImageRequestHandler(ciImage: ciImage)
        
        DispatchQueue.global(qos: .userInteractive).async {
            do {
                try imageHandler.perform([request])
            } catch {
                print("Error")
            }
        }
    }
    
}

